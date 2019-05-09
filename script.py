import BinSymReg as bsr

print("Hello World")
monX=[[True,False,True],[True, True, False]]
monY= [True, False]
nbgene=6
S1=bsr.create_solver(5,monX,monY,nbgene)
print(S1)
print(bsr.print_fonct(S1))

