#최종본
class VDmech:
	"""docstring for VDmech"""
	def __init__(self):
		self.balance = 0
		self.earnMoney = 0
		self.dict = [['water',900,10],['pocari',1200,0],['fanta',800,5]]
		self.goodsManage = {1:self.newGoods,2:self.modifyGoods,3:self.delGoods}

	def disp(self):
		for i in range(len(self.dict)):
			print(self.dict[i][0],end = "\t\t")
		print()
		for i in range(len(self.dict)):
			print(self.dict[i][1],end = "\t\t")
		print()
		for i in range(len(self.dict)):
			if(self.dict[i][2]):
				print(self.dict[i][2],"개",end = "\t\t")
			else:
				print("품절",end = "\t\t")
		print("\n--------------------------------잔액 : ",self.balance)


	def payment(self):
		pay = int(input("입금 가격 : "))
		self.balance += pay

	def buy(self):
		print("-----------구매 가능 목록----------")
		for i in range(len(self.dict)):
			if(	self.dict[i][1] <= self.balance and self.dict[i][2]):
				print(i+1,".",self.dict[i][0],end = "\t")
		choice = int(input("\n"))-1
		if(	choice < 0 
			or choice > len(self.dict) 
			or self.dict[choice][1] > self.balance 
			or self.dict[choice][2] <= 0):
			print("해당 제품은 구매할 수 없습니다. 다시 선택해주십시오.")
		else:
			self.balance -= self.dict[choice][1]
			self.earnMoney += self.dict[choice][1]
			self.dict[choice][2] -= 1
			print("--------------구매 완료!-----------")

	def balanceClear(self):
		self.balance = 0
		print("--------------정산 완료!-----------")

	def goods(self):
		choice = int(input("1:신제품 입고 2:기존 제품 입고 3:제품 판매 중지\n"))
		if(choice>3 or choice<0):
			print("잘못된 접근입니다.")
		else:
			self.goodsManage[choice]()

	def newGoods(self):
		self.dict.append([])
		self.dict[-1].append(input("제품 이름 : "))
		self.dict[-1].append(int(input("가격 : ")))
		self.dict[-1].append(int(input("수량 : ")))
		print("--------------입고 완료!-----------")

	def modifyGoods(self):
		print("-----------관리 가능 제품 목록----------")
		for i in range(len(self.dict)):
			print(i+1,".",self.dict[i][0],end = "\t")
		choice1 = int(input("\n"))-1
		if(choice1 < 0 or choice1 >= len(self.dict)):
			print("잘못된 접근입니다.")
		else:
			self.dict[choice1][2] = int(input("입고 수량 : "))
			choice2 = input("해당 제품의 가격을 조정하시겠습니까? y/n :")
			if(choice2 == 'y'):
				self.dict[choice1][1] = int(input("가격 : "))
			print("--------------입고 완료!-----------")

	def delGoods(self):
		print("-----------삭제 가능 제품 목록----------")
		for i in range(len(self.dict)):
			print(i+1,".",self.dict[i][0],end = "\t")
		choice1 = int(input("\n"))-1
		if(choice1 < 0 or choice1 >= len(self.dict)):
			print("잘못된 접근입니다.")
		else:
			del self.dict[choice1]
			print("--------------삭제 완료!-----------")
	def sales(self):
		print("매출액 : ",self.earnMoney)
		choice = input("매출액을 초기화하시겠습니까? y/n :")
		if(choice == 'y'):
			self.earnMoney = 0
			print("--------------매출 초기화 완료!-----------")

if __name__ == "__main__":
	call = VDmech()
	funcList = {1:call.payment,2:call.buy,3:call.balanceClear,4:call.goods,5:call.sales}
	while(True):
		call.disp()
		num = int(input("1:입금 2:구매 3: 거스름돈 정산 4:물품 관리 5:매출 확인\n"))
		if(num < 6 and num > 0):
			funcList[num]()