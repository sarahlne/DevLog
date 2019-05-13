import BinSymReg as bsr

print("Hello World")
monX=[[True,False,True],[True, True, False]]
monY= [True,False]
gene=20
lamba=5
S1=bsr.create_solver(gene,monX,monY,lamba)
bsr.print_fonct(S1)
bsr.evolve(S1)
bsr.print_fonct(S1)
print(bsr.get_fitness(S1))
test= [True,False]
print(bsr.calcul(S1,test))
#bsr.gethistoric(S1)

