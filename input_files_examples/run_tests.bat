@echo off
chcp 866 >nul
set program=ExpressionToTeX.exe

echo. > results.txt
echo 01 - ‚ëà ¦¥­¨¥ á ­¥áª®«ìª¨¬¨ ¢«®¦¥­­ë¬¨ ®¯¥à æ¨ï¬¨ >> results.txt
echo.  >> results.txt
%program% input1.txt output.txt >> results.txt
echo ‚•Ž„›… „€›…: >> results.txt
type input1.txt >> results.txt
echo.  >> results.txt
echo ‚›•Ž„›… „€›…: >> results.txt
type output.txt >> results.txt

echo.  >> results.txt
echo.  >> results.txt
echo 02 - ‚ëà ¦¥­¨¥ á ­¥áª®«ìª¨¬¨ ®¯¥à æ¨ï¬¨ >> results.txt
echo.  >> results.txt
%program% input2.txt output.txt >> results.txt
echo ‚•Ž„›… „€›…: >> results.txt
type input2.txt >> results.txt
echo.  >> results.txt
echo ‚›•Ž„›… „€›…: >> results.txt
type output.txt >> results.txt

echo.  >> results.txt
echo.  >> results.txt
echo 03 - à®áâ®¥ ¢ëà ¦¥­¨¥ >> results.txt
echo.  >> results.txt
%program% input3.txt output.txt >> results.txt
echo ‚•Ž„›… „€›…: >> results.txt
type input3.txt >> results.txt
echo.  >> results.txt
echo ‚›•Ž„›… „€›…: >> results.txt
type output.txt >> results.txt

echo.  >> results.txt
echo.  >> results.txt
echo 04 - ‚ëà ¦¥­¨¥ á ª¢ ­â®à®¬ >> results.txt
echo.  >> results.txt
%program% input4.txt output.txt >> results.txt
echo ‚•Ž„›… „€›…: >> results.txt
type input4.txt >> results.txt
echo.  >> results.txt
echo ‚›•Ž„›… „€›…: >> results.txt
type output.txt >> results.txt

echo.  >> results.txt
echo.  >> results.txt
echo 05 - ¥¢¥à­ë¥ ¢å®¤­ë¥ ¤ ­­ë¥: ­¥¤®áâ â®ç­® ®¯¥à ­¤®¢ ¤«ï ®¯¥à æ¨¨ >> results.txt
echo ‚•Ž„›… „€›…: >> results.txt
type input5.txt >> results.txt
echo.  >> results.txt
%program% input5.txt output.txt >> results.txt

echo.  >> results.txt
echo.  >> results.txt
echo 06 - ¥¢¥à­ë¥ ¢å®¤­ë¥ ¤ ­­ë¥: ­¥áª®«ìª® áâà®ª >> results.txt
echo ‚•Ž„›… „€›…: >> results.txt
type input6.txt >> results.txt
echo.  >> results.txt
%program% input6.txt output.txt >> results.txt

echo.  >> results.txt
echo.  >> results.txt
echo 07 - ¥¢¥à­ë¥ ¢å®¤­ë¥ ¤ ­­ë¥: ­¥¢¥à­ ï ¯¥à¥¬¥­­ ï >> results.txt
echo ‚•Ž„›… „€›…: >> results.txt
type input7.txt >> results.txt
echo.  >> results.txt
%program% input7.txt output.txt >> results.txt

echo.  >> results.txt
echo.  >> results.txt
echo 08 - ¥¢¥à­ë¥ ¢å®¤­ë¥ ¤ ­­ë¥: ­¥¢¥à­ ï ®¯¥à æ¨ï >> results.txt
echo ‚•Ž„›… „€›…: >> results.txt
type input8.txt >> results.txt
echo.  >> results.txt
%program% input8.txt output.txt >> results.txt

echo.  >> results.txt
echo.  >> results.txt
echo 09 - ¥¢¥à­ë¥ ¢å®¤­ë¥ ¤ ­­ë¥: ­¥¢¥à­®¥ ª®«¨ç¥áâ¢® ®¯¥à ­¤®¢ >> results.txt
echo ‚•Ž„›… „€›…: >> results.txt
type input9.txt >> results.txt
echo.  >> results.txt
%program% input9.txt output.txt >> results.txt

echo.  >> results.txt
echo.  >> results.txt
echo 10 - ¥¢¥à­ë¥ ¢å®¤­ë¥ ¤ ­­ë¥: ¯ãáâ®© ä ©« >> results.txt
echo ‚•Ž„›… „€›…: >> results.txt
type input10.txt >> results.txt
echo.  >> results.txt
%program% input10.txt output.txt >> results.txt