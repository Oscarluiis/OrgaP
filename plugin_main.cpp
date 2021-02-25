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
            rlutil::setBackgroundColor(regs[Register::t1]);
        }


        case 22:
        {
             rlutil::setColor(regs[Register::a1]);
            
            
            return ErrorCode::Ok;
        }

        case 23:
        {
            
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
