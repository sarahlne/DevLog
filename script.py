import BinSymReg as bsr

print("Hello World")
monX=[[True,False,True],[True, True, False]]
monY= [True, False]
nbgene=6
nbenfant=5
S1=bsr.create_solver(53,monX,monY,3)
print(S1)
bsr.print_fonct(S1)
monY= [True,False]
gene=100
lamba=5
S1=bsr.create_solver(gene,monX,monY,lamba)
bsr.print_fonct(S1)
bsr.evolve(S1)
bsr.print_fonct(S1)
print(bsr.get_fitness(S1))
test= [1,0,1]
print("juste avant Calcule")
print(bsr.calcul(S1,test))
histfit=[0 for i in range(gene)]
print(bsr.get_historic(S1,histfit))


