import BinSymReg as bsr

print("Hello World")
monX=[[True,False,True],[True, True, False]]
monY= [True,False]
gene=100
lamba=5
S1=bsr.create_solver(gene,monX,monY,lamba)
bsr.print_fonct(S1)
bsr.evolve(S1)
bsr.print_fonct(S1)
print(bsr.get_fitness(S1))
test= [True,False]
print(bsr.calcul(S1,test))
histfit=[0 for i in range(gene)]
print(bsr.get_historic(S1,histfit))


