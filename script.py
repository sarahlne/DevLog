import BinSymReg as bsr

print("Hello World")
monX=[[True,False,True],[True, True, False]]
monY= [True, False]
nbgene=6
nbenfant=5
S1=bsr.create_solver(53,monX,monY,3)
print(S1)
print(bsr.print_fonct(S1))

