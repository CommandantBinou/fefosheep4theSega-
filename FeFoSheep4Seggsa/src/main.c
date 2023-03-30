/*Made using Sgdk and VSCode extension including the default template, special thanks to Ohsat and Pigsy for their wonderful tutorials*/
#include <genesis.h>

/*Region check ripped-off from Ohsat's tutorial but implemented into a general purpose function :)
0 is EU-Pal, 1 is Jap-PAL, 2 is US-NTSC other, 3 is JP-Ntsc
*/
u8 regCheck(){
    u8 regi = *(u8 *)0xA10001;
    u8 regionC = 0;
    if(regi & (1 << 7))
    {
        regionC+=0;
    } else
    {
        regionC+=1;
    }
        if(regi & (1 << 6))
    {
        regionC+=0;
    } else
    {
        regionC+=2;
    }

    return(regionC);
}

int main()
{   

    fix32 timetest;
    startTimer(0);
    u8 r = regCheck();
    u8 rFirst = r;
    //int fefoCount = 0;
    VDP_drawText("welCum to feefshesh 4 da sega", 0,0);
    VDP_drawText("curent reegion:", 0,24);
    while(1)
    {
        VDP_clearTextArea(0,10,40,1);
        VDP_clearTextArea(0,6,40,1);
        timetest = getTimeAsFix32(0);
        r = regCheck();
        VDP_clearTextArea(15,15,4,1);
        switch(r)
        {
            case (3):
                VDP_drawText("JpNt", 15,24);
                break;
            case (2):
                VDP_drawText("UsNt", 15,24);
                break;
            case (1):
                VDP_drawText("JPal", 15,24);
                break;
            default:
                VDP_drawText("EPal", 15,24);
            break;

        }
        if (r != rFirst )
        {
            VDP_drawText("did u fckin change ur region", 0,22);
        }
        if (timetest >=2000 )
        {
            VDP_drawText("frii geam will arive", 0,1);
        }
        if (timetest >=4000 )
        {
            VDP_drawText("frii geam wenn?", 0,2);
        }
        if (timetest >=6000 )
        { 
            VDP_drawText("hop u enjoi ur stae", 0,3);
        }
        if (timetest >=8000)
        {
            VDP_drawText("assqin discord server for frii gams", 0,4);
        }
        SYS_doVBlankProcess();
    }
    return (0);
}

