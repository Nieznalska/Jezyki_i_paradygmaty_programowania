#def rownanie
import numpy as np
import cmath as cm
from functools import reduce

class PierwiastkiR(object):
    def __init__(self, wspol, delt):
        self.wsp = wspol
        self.com = []
        self.wyniki = []
        self.delta = delt

class UjemnaDelta(PierwiastkiR):
    def __init__(self,wspol, delt):
        super().__init__(wspol,delt)
    def obliczPierwiastekR(self):
        pdelta = np.sqrt(np.abs(self.delta))
        self.com.append(complex(((-1.0 *self.wsp[1]) / (2 * self.wsp[0])),(-pdelta / (2 * self.wsp[0]))))
        self.com.append(np.conj(self.com[0]))
        self.com[0]=np.sqrt(self.com[0])
        self.com[1]=-np.sqrt(self.com[1])
        self.com.append(np.conj(self.com[0]))
        self.com.append(np.conj(self.com[1]))
    
    
    def wyswietlPierwiastki(self):
        cnt=1
        for x in self.com:
            print("x"+str(cnt)+"= "+str(x))
            cnt+=1
        print("Suma: "+str(self.wyniki[0]))
        print("Roznica: "+str(self.wyniki[1]))
    def dodajPierwiaskiRownania(self):
        self.wyniki.append(sum(self.com))
            
    def odejmijPierwiastkiRownania(self):
        self.wyniki.append(reduce((lambda a, b: a - b), self.com))    
    def pomnozPierwiastkiRownania(self):
        self.wyniki.append(reduce((lambda a,b: a*b), self.com))
        
class DodatniaDelta(PierwiastkiR):
    def __init__(self, wspol, delt):
        super().__init__(wspol, delt)
    def obliczPierwiastekR(self):
        pdelta = np.sqrt(np.fabs(self.delta))
        x1r = (-self.wsp[1] - pdelta) / (2*self.wsp[0]);
        x2r = (-self.wsp[1] + pdelta) / (2*self.wsp[0]);
        
        self.com.append(np.sqrt(complex(x1r)))
        self.com.append(np.sqrt(complex(x2r)))
        if(x1r >= 0):
            self.com.append(complex( -np.real(self.com[0]), np.imag(self.com[0])))
        if(x1r < 0):
            self.com.append(np.conj(self.com[0]))
        if(x2r>= 0):
            self.com.append(complex(-np.real(self.com[1]), np.imag(self.com[1])))
        if(x2r < 0):
            self.com.append(np.conj(self.com[1]))
    def wyswietlPierwiastki(self):
        cnt=1
        for x in self.com:
            print("x"+str(cnt)+"= "+str(x))
            cnt+=1
        print("Suma: "+str(self.wyniki[0]))
        print("Roznica: "+str(self.wyniki[1]))
    def dodajPierwiaskiRownania(self):
        self.wyniki.append(sum(self.com))       
    def odejmijPierwiastkiRownania(self):
        self.wyniki.append(reduce((lambda a, b: a - b), self.com))
        
class ZerowaDelta(PierwiastkiR):
    def __init__(self, wspol,delt):
        super().__init__(wspol, delt)
    def obliczPierwiastekR(self):
        if(self.wsp[0] == 0 and self.wsp[2] == 0):
            self.com.append(0,0)
        else:
            x1r = -self.wsp[1] / (2*self.wsp[0])
            if(x1r > 0):
                self.com.append(np.sqrt(complex(x1r)))
                self.com.append(complex( -np.real(self.com[0]), np.imag(self.com[0])))
            if(x1r < 0):
                self.com.append(complex(x1r))
                self.com[0] = np.sqrt(self.com[0]);
                self.com.append(complex( np.real(self.com[0]), -np.imag(self.com[0])))
    def wyswietlPierwiastki(self):
        cnt=1
        for x in self.com:
            print("x"+str(cnt)+"= "+str(x))
            cnt+=1
        print("Suma: "+str(self.wyniki[0]))
        print("Roznica: "+str(self.wyniki[1]))
    def dodajPierwiaskiRownania(self):
        self.wyniki.append(sum(self.com))       
    def odejmijPierwiastkiRownania(self):
        self.wyniki.append(reduce((lambda a, b: a - b), self.com))
        
class RownanieLiniowe(PierwiastkiR):
    def __init__(self, wspol, delt):
        super().__init__(wspol, delt)
    def obliczPierwiastki(self):
        if(self.wsp[1] != 0 and self.wsp[2] != 0):
            t = (-1.0 * self.wsp[2])/self.wsp[1]
            print(t)
            self.com.append(np.sqrt(complex(t)))
            if(t>0):
                self.com.append(complex( -np.real(self.com[0])))
            elif(t<0):
                self.com.append(complex( np.conj(self.com[0])))
        elif(self.wsp[1] != 0 and self.wsp[2] ==0):
            self.com.append(0)
            
    def wyswietlPierwiastki(self):
        cnt=1
        for x in self.com:
            print("x"+str(cnt)+"= "+str(x))
            cnt+=1
        print("Suma: "+str(self.wyniki[0]))
        print("Roznica: "+str(self.wyniki[1]))
    def dodajPierwiaskiRownania(self):
        self.wyniki.append(sum(self.com))       
    def odejmijPierwiastkiRownania(self):
        self.wyniki.append(reduce((lambda a, b: a - b), self.com))
     
