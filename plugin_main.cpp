#include <iostream>
#include <easm.h>
#include <rlutil.h>

extern "C" ErrorCode handleSyscall(uint32_t *regs, void *mem, MemoryMap *mem_map)
{
    unsigned v0 = regs[Register::v0];

    switch (v0)
    {
        case 20:
        {
            int a0 = regs[Register::a0];
            int a1 = regs[Register::a1];
            regs[Register::v0] = a0 + a1;
            return ErrorCode::Ok;
        }

        case 21:
        {
            //tabla de multiplicar
            int a0 = regs[Register::a0]; //numero
            int a1 = regs[Register::a1]; //limite
            int a2 = regs[Register::a2]; //color
            std::cout<<"Tabla del: "<<a0<<'\n';
            //sint contador=0; 
            for(size_t i = 0; i <= a1; i++){
                
                rlutil::setColor(a2);
                int resultado = a0*i;
                std::cout<<a0 <<"x"<<i<<": "<<resultado<<'\n';
                
            }
            rlutil::resetColor();
            
            return ErrorCode::Ok;
        }

        case 22:
        {
             int a0 = regs[Register::a0]; //numero
             std::string arreglo[] = {"Soy Azul", "Soy Verde", "Soy Cyan", 
                                    "Soy Rojo","Soy Magenta"};
            a0 = 1;
            for(size_t i=0; i < 5; i++){
                rlutil::setColor(a0);
                std::cout<<arreglo[i]<<'\n';
                a0++;
            }
            rlutil::resetColor();
            
            return ErrorCode::Ok;
        }

        case 23:
        {
            //Mayor y menor
             int a0 = regs[Register::a0]; //numero
             int a1 = regs[Register::a1]; //numero
             int t0 = regs[Register::t0]; //background
            
            if(a0 > a1){
                t0 = 2;
                rlutil::setBackgroundColor(t0);
                t0 = 15 ;
                rlutil::setColor(t0);
                std::cout<<"Es mayor a0 que a1"<<'\n';
                 rlutil::resetColor();
            }else if(a0 < a1){
                t0 = 4;
                rlutil::setBackgroundColor(t0);
                t0 = 0;
                rlutil::setColor(t0);
                std::cout<<"Es menor a0 que a1"<<'\n';
                rlutil::resetColor();
            }else{
                std::cout<<"Iguales"<<'\n';
            }
            rlutil::resetColor();
            return ErrorCode::Ok;
        }
        case 24:
        {   
            //limpiar la pantalla
            rlutil::cls();
            return ErrorCode::Ok;
        }
        
        case 25:
        {
            std::cout<<"No se deberia ver el cursor"<<'\n';
            rlutil::hidecursor();
            return ErrorCode::Ok;
        }
        
        case 26:
        {
            std::cout<<"Se deberia ver el cursor"<<'\n';
            rlutil::showcursor();
            return ErrorCode::Ok;
        }
        default:
            if (v0 > 20 && v0 <= 50)
            {
                std::cout << "Syscall: " << v0 << '\n' << std::flush;
                return ErrorCode::Ok;
            }
            else
            {
                return ErrorCode::SyscallNotImplemented;
            }
    }
}
