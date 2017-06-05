/* Inspired a bit by evi1wombat */
/* https://www.youtube.com/watch?v=hfmGnLMlKvs */

static short led_art[10][8]={
#if 1
/* 1 = aperture */
	{               /* 7654321076543210 */
	0x0380,		/*       ***        */
	0x0760,		/*      *** **      */
	0x0a50,		/*     * *  * *     */
	0x0c20,		/*     **    *      */
	0x0430,		/*      *    **     */
	0x0a50,		/*     * *  * *     */
	0x06e0,		/*      ** ***      */
	0x01c0,		/*        ***       */
	},
#else
/* 1 = aperture */
	{		/* 7654321076543210 */
	0x03c0,		/*       ****       */
	0x0560,		/*      * * **      */
	0x0c10,		/*     **     *     */
	0x0830,		/*     *     **     */
	0x0c10,		/*     **     *     */
	0x0830,		/*     *     **     */
	0x06a0,		/*      ** * *      */
	0x03c0,		/*       ****       */
	},
#endif
	{
/* 2 = radiation */
	0x01c0,		/*        ***      */
	0x01c0,		/*        ***      */
	0x0080,		/*         *       */
	0x0000,		/*                 */
	0x0080,		/*         *       */
	0x0e38,		/*     ***   ***   */
	0x0630,		/*      **   **    */
	0x0220,		/*       *   *     */
	},
/* 3 = atom */
	{
	0x0180,		/*        **       */
	0x1a58,		/*    ** *  * **   */
	0x15a8,		/*    * * ** * *   */
	0x0a50,		/*     * *  * *    */
	0x0a50,		/*     * *  * *    */
	0x15a8,		/*    * * ** * *   */
	0x1a58,		/*    ** *  * **   */
	0x0180,		/*        **       */
	},
/* 4 = broken heart */
	{
	0x0c30,		/*     **    **    */
	0x1e78,		/*    ****  ****   */
	0x1ce8,		/*    ***  *** *   */
	0x1e78,		/*    ****  ****   */
	0x0cf0,		/*     **  ****    */
	0x0660,		/*      **  **     */
	0x03c0,		/*       ****      */
	0x0180,		/*        **       */
	},
/* 5 = explosion */
	{
	0x0200,		/*       *        */
	0x0310,		/*       **   *   */
	0x11a0,		/*    *   ** *    */
	0x0fe8,		/*     ******* *  */
	0x03f0,		/*       ******   */
	0x07e0,		/*      ******    */
	0x0db0,		/*     ** ** **   */
	0x1118,		/*    *   *   **  */
	},
/* 6 = fire */
	{
	0x0290,		/*       * *  *   */
	0x08c0,		/*     *   **     */
	0x01c0,		/*        ***     */
	0x03e0,		/*       *****    */
	0x0760,		/*      *** **    */
	0x0660,		/*      **  **    */
	0x06c0,		/*      ** **     */
	0x0280,		/*       * *      */
	},
/* 7 = check */
	{
	0x001c,		/*          ***   */
	0x003c,		/*         ****   */
	0x0078,		/*        ****    */
	0x18f0,		/*  **   ****     */
	0x3de0,		/* **** ****      */
	0x1fc0,		/*  *******       */
	0x0f80,		/*   *****        */
	0x0700,		/*    ***         */
	},
/* 8 = black mesa */
	{
	0x03c0,		/*      ****      */
	0x0420,		/*     *    *     */
	0x0810,		/*    *      *    */
	0x09d0,		/*    *  *** *    */
	0x09f0,		/*    *  *****    */
	0x09f0,		/*    *  *****    */
	0x07e0,		/*     ******     */
	0x03c0,		/*      ****      */
	},
/* 9 = cake, delicious and moist */
	{
	0x0df8,		/*    ** ******  */
	0x1f80,		/*   ******      */
	0x1c18,		/*   ***     **  */
	0x1c60,		/*   ***   **    */
	0x1f80,		/*   ******      */
	0x1c18,		/*   ***     **  */
	0x0c60,		/*    **   **    */
	0x0780,		/*     ****      */
	},
/* : = GLaDOS */
	{
	0x18f8,		/*    **   *****  */
	0x3124,		/*   **   *  *  * */
	0x11c4,		/*    *   ***   * */
	0x3224,		/*   **  *   *  * */
	0x12a4,		/*    *  * * *  * */
	0x32a4,		/*   **  * * *  * */
	0x3224,		/*   **  *   *  * */
	0x19c8,		/*    **  ***  *  */
	},
};

static char ascii_art[10][21][41]={
{
/* 1 = aperture */
	{"              .,-:;//;:=,"},
	{"          . :H@@@MM@M#H/.,+%;,"},
	{"       ,/X+ +M@@M@MM%=,-%HMMM@X/,"},
	{"     -+@MM; $M@@MH+-,;XMMMM@MMMM@+-"},
	{"    ;@M@@M- XM@X;. -+XXXXXHHH@M@M#@/."},
	{"  ,%MM@@MH ,@%=            .---=-=:=,."},
	{"  =@#@@@MX .,              -%HX$$%%%+;"},
	{" =-./@M@M$                  .;@MMMM@MM:"},
	{" X@/ -$MM/                    .+MM@@@M$"},
	{",@M@H: :@:                    . =X#@@@@-"},
	{",@@@MMX, .                    /H- ;@M@M="},
	{".H@@@@M@+,                    %MM+..%#$."},
	{" /MMMM@MMH/.                  XM@MH; =;"},
	{"  /%+%$XHH@$=              , .H@@@@MX,"},
	{"   .=--------.           -%H.,@@@@@MX,"},
	{"   .%MM@@@HHHXX$$$%+- .:$MMX =M@@MM%."},
	{"     =XMMM@MM@MM#H;,-+HMM@M+ /MMMX="},
	{"       =%@M@M#@$-.=$@MM@@@M; %M%="},
	{"         ,:+$+-,/H#MMMMMMM@= =,"},
	{"               =++%%%%+/:-."},
},
{
/* 2 = radiation */
	{"             =+$HM####@H%;,"},
	{"          /H###############M$,"},
	{"          ,@################+"},
	{"           .H##############+"},
	{"             X############/"},
	{"              $##########/"},
	{"               %########/"},
	{"                /X/;;+X/"},
	{" "},
	{"                 -XHHX-"},
	{"                ,######,"},
	{"#############X  .M####M.  X#############"},
	{"##############-   -//-   -##############"},
	{"X##############%,      ,+##############X"},
	{"-##############X        X##############-"},
	{" %############%          %############%"},
	{"  %##########;            ;##########%"},
	{"   ;#######M=              =M#######;"},
	{"    .+M###@,                ,@###M+."},
	{"       :XH.                  .HX:"},
},
{
/* 3 = atom */
	{"                 =/;;/-"},
	{"                +:    //"},
	{"               /;      /;"},
	{"              -X        H."},
	{".//;;;:;;-,   X=        :+   .-;:=;:;%;."},
	{"M-       ,=;;;#:,      ,:#;;:=,       ,@"},
	{":%           :%.=/++++/=.$=           %="},
	{" ,%;         %/:+/;,,/++:+/         ;+."},
	{"   ,+/.    ,;@+,        ,%H;,    ,/+,"},
	{"      ;+;;/= @.  .H##X   -X :///+;"},
	{"      ;+=;;;.@,  .XM@$.  =X.//;=%/."},
	{"   ,;:      :@%=        =$H:     .+%-"},
	{" ,%=         %;-///==///-//         =%,"},
	{";+           :%-;;;:;;;;-X-           +:"},
	{"@-      .-;;;;M-        =M/;;;-.      -X"},
	{" :;;::;;-.    %-        :+    ,-;;-;:=="},
	{"              ,X        H."},
	{"               ;/      %="},
	{"                //    +;"},
	{"                 ,////,"},
},
{
/* 4 = broken heart */
	{"                          .,---."},
	{"                        ,/XM#MMMX;,"},
	{"                      -%##########M%,"},
	{"                     -@######%  $###@="},
	{"      .,--,         -H#######$   $###M:"},
	{"   ,;$M###MMX;     .;##########$;HM###X="},
	{" ,/@##########H=      ;################+"},
	{"-+#############M/,      %##############+"},
	{"%M###############=      /##############:"},
	{"H################      .M#############;."},
	{"@###############M      ,@###########M:."},
	{"X################,      -$=X#######@:"},
	{"/@##################%-     +######$-"},
	{".;##################X     .X#####+,"},
	{" .;H################/     -X####+."},
	{"   ,;X##############,       .MM/"},
	{"      ,:+$H@M#######M#$-    .$$="},
	{"           .,-=;+$@###X:    ;/=."},
	{"                  .,/X$;   .::,"},
	{"                      .,    .."},
},
{
/* 5 = explosion */
	{"            .+"},
	{"             /M;"},
	{"              H#@:              ;,"},
	{"              -###H-          -@/"},
	{"               %####$.  -;  .%#X"},
	{"                M#####+;#H :M#M."},
	{"..          .+/;%#########X###-"},
	{" -/%H%+;-,    +##############/"},
	{"    .:$M###MH$%+############X  ,--=;-"},
	{"        -/H#####################H+=."},
	{"           .+#################X."},
	{"         =%M####################H;."},
	{"            /@###############+;;/%%;,"},
	{"         -%###################$."},
	{"       ;H######################M="},
	{"    ,%#####MH$%;+#####M###-/@####%"},
	{"  :$H%+;=-      -####X.,H#   -+M##@-"},
	{" .              ,###;    ;      =$##+"},
	{"                .#H,               :XH,"},
	{"                 +                   .;-"},
},
{
/* 6 = fire */
	{"                     -$-"},
	{"                    .H##H,"},
	{"                   +######+"},
	{"                .+#########H."},
	{"              -$############@."},
	{"            =H###############@  -X:"},
	{"          .$##################:  @#@-"},
	{"     ,;  .M###################;  H###;"},
	{"   ;@#:  @###################@  ,#####:"},
	{" -M###.  M#################@.  ;######H"},
	{" M####-  +###############$   =@#######X"},
	{" H####$   -M###########+   :#########M,"},
	{"  /####X-   =########%   :M########@/."},
	{"    ,;%H@X;   .$###X   :##MM@%+;:-"},
	{"                 .."},
	{"  -/;:-,.              ,,-==+M########H"},
	{" -##################@HX%%+%%$%%%+:,,"},
	{"    .-/H%%%+%%$H@###############M@+=:/+:"},
	{"/XHX%:#####MH%=    ,---:;;;;/%%XHM,:###$"},
	{"$@#MX %+;-                           ."},
},
{
/* 7 = check */
	{"                                     :X-"},
	{"                                  :X###"},
	{"                                ;@####@"},
	{"                              ;M######X"},
	{"                            -@########$"},
	{"                          .$##########@"},
	{"                         =M############-"},
	{"                        +##############$"},
	{"                      .H############$=."},
	{"         ,/:         ,M##########M;."},
	{"      -+@###;       =##########M;"},
	{"   =%M#######;     :#########M/"},
	{"-$M###########;   :#########/"},
	{" ,;X###########; =########$."},
	{"     ;H#########+#######M="},
	{"       ,+##############+"},
	{"          /M#########@-"},
	{"            ;M######%"},
	{"              +####:"},
	{"               ,$M-"},
},
{
/* 8 = black mesa */
	{"           .-;+$XHHHHHHX$+;-."},
	{"        ,;X@@X%/;=----=:/%X@@X/,"},
	{"      =$@@%=.              .=+H@X:"},
	{"    -XMX:                      =XMX="},
	{"   /@@:                          =H@+"},
	{"  %@X,                            .$@$"},
	{" +@X.                               $@%"},
	{"-@@,                                .@@="},
	{"%@%                                  +@$"},
	{"H@:                                  :@H"},
	{"H@:         :HHHHHHHHHHHHHHHHHHX,    =@H"},
	{"%@%         ;@M@@@@@@@@@@@@@@@@@H-   +@$"},
	{"=@@,        :@@@@@@@@@@@@@@@@@@@@@= .@@:"},
	{" +@X        :@@@@@@@@@@@@@@@M@@@@@@:%@%"},
	{"  $@$,      ;@@@@@@@@@@@@@@@@@M@@@@@@$."},
	{"   +@@HHHHHHH@@@@@@@@@@@@@@@@@@@@@@@+"},
	{"    =X@@@@@@@@@@@@@@@@@@@@@@@@@@@@X="},
	{"      :$@@@@@@@@@@@@@@@@@@@M@@@@$:"},
	{"        ,;$@@@@@@@@@@@@@@@@@@X/-"},
	{"           .-;+$XXHHHHHX$+;-."},
},
{
/* 9 = cake, delicious and moist */
	{"            ,:/+/-"},
	{"            /M/              .,-=;//;-"},
	{"       .:/= ;MH/,    ,=/+%$XH@MM#@:"},
	{"      -$##@+$###@H@MMM#######H:.    -/H#"},
	{" .,H@H@ X######@ -H#####@+-     -+H###@X"},
	{"  .,@##H;      +XM##M/,     =%@###@X;-"},
	{"X%-  :M##########$.    .:%M###@%:"},
	{"M##H,   +H@@@$/-.  ,;$M###@%,          -"},
	{"M####M=,,---,.-%%H####M$:          ,+@##"},
	{"@##################@/.         :%H##@$-"},
	{"M###############H,         ;HM##M$="},
	{"#################.    .=$M##M$="},
	{"################H..;XM##M$=          .:+"},
	{"M###################@%=           =+@MH%"},
	{"@################M/.          =+H#X%="},
	{"=+M##############M,       -/X#X+;."},
	{"  .;XM##########H=    ,/X#H+:,"},
	{"     .=+HM######M+/+HM@+=."},
	{"         ,:/%XM####H/."},
	{"              ,.:=-."},
},
{
/* : = GLaDOS */
	{"       #+ @      # #              M#@"},
	{" .    .X  X.%##@;# #   +@#######X. @#%"},
	{"   ,==.   ,######M+  -#####%M####M-    #"},
	{"  :H##M%:=##+ .M##M,;#####/+#######% ,M#"},
	{" .M########=  =@#@.=#####M=M#######=  X#"},
	{" :@@MMM##M.  -##M.,#######M#######. =  M"},
	{"             @##..###:.    .H####. @@ X,"},
	{"   ############: ###,/####;  /##= @#. M"},
	{"           ,M## ;##,@#M;/M#M  @# X#% X#"},
	{".%=   ######M## ##.M#:   ./#M ,M #M ,#$"},
	{"##/         $## #+;#: #### ;#/ M M- @# :"},
	{"#+ #M@MM###M-;M #:$#-##$H# .#X @ + $#. #"},
	{"      ######/.: #%=# M#:MM./#.-#  @#: H#"},
	{"+,.=   @###: /@ %#,@  ##@X #,-#@.##% .@#"},
	{"#####+;/##/ @##  @#,+       /#M    . X,"},
	{"   ;###M#@ M###H .#M-     ,##M  ;@@; ###"},
	{"   .M#M##H ;####X ,@#######M/ -M###$  -H"},
	{"    .M###%  X####H  .@@MM@;  ;@#M@"},
	{"      H#M    /@####/      ,++.  / ==-,"},
	{"               ,=/:, .+X@MMH@#H  #####$="},
}
};

