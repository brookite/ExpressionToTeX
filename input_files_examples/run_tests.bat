@echo off
chcp 866 >nul
set program=ExpressionToTeX.exe

echo. > results.txt
echo 01 - ��ࠦ���� � ��᪮�쪨�� �������묨 �����ﬨ >> results.txt
echo.  >> results.txt
%program% input1.txt output.txt >> results.txt
echo ������� ������: >> results.txt
type input1.txt >> results.txt
echo.  >> results.txt
echo �������� ������: >> results.txt
type output.txt >> results.txt

echo.  >> results.txt
echo.  >> results.txt
echo 02 - ��ࠦ���� � ��᪮�쪨�� �����ﬨ >> results.txt
echo.  >> results.txt
%program% input2.txt output.txt >> results.txt
echo ������� ������: >> results.txt
type input2.txt >> results.txt
echo.  >> results.txt
echo �������� ������: >> results.txt
type output.txt >> results.txt

echo.  >> results.txt
echo.  >> results.txt
echo 03 - ���⮥ ��ࠦ���� >> results.txt
echo.  >> results.txt
%program% input3.txt output.txt >> results.txt
echo ������� ������: >> results.txt
type input3.txt >> results.txt
echo.  >> results.txt
echo �������� ������: >> results.txt
type output.txt >> results.txt

echo.  >> results.txt
echo.  >> results.txt
echo 04 - ��ࠦ���� � �����஬ >> results.txt
echo.  >> results.txt
%program% input4.txt output.txt >> results.txt
echo ������� ������: >> results.txt
type input4.txt >> results.txt
echo.  >> results.txt
echo �������� ������: >> results.txt
type output.txt >> results.txt

echo.  >> results.txt
echo.  >> results.txt
echo 05 - ������ �室�� �����: �������筮 ���࠭��� ��� ����樨 >> results.txt
echo ������� ������: >> results.txt
type input5.txt >> results.txt
echo.  >> results.txt
%program% input5.txt output.txt >> results.txt

echo.  >> results.txt
echo.  >> results.txt
echo 06 - ������ �室�� �����: ��᪮�쪮 ��ப >> results.txt
echo ������� ������: >> results.txt
type input6.txt >> results.txt
echo.  >> results.txt
%program% input6.txt output.txt >> results.txt

echo.  >> results.txt
echo.  >> results.txt
echo 07 - ������ �室�� �����: ����ୠ� ��६����� >> results.txt
echo ������� ������: >> results.txt
type input7.txt >> results.txt
echo.  >> results.txt
%program% input7.txt output.txt >> results.txt

echo.  >> results.txt
echo.  >> results.txt
echo 08 - ������ �室�� �����: ����ୠ� ������ >> results.txt
echo ������� ������: >> results.txt
type input8.txt >> results.txt
echo.  >> results.txt
%program% input8.txt output.txt >> results.txt

echo.  >> results.txt
echo.  >> results.txt
echo 09 - ������ �室�� �����: ����୮� ������⢮ ���࠭��� >> results.txt
echo ������� ������: >> results.txt
type input9.txt >> results.txt
echo.  >> results.txt
%program% input9.txt output.txt >> results.txt

echo.  >> results.txt
echo.  >> results.txt
echo 10 - ������ �室�� �����: ���⮩ 䠩� >> results.txt
echo ������� ������: >> results.txt
type input10.txt >> results.txt
echo.  >> results.txt
%program% input10.txt output.txt >> results.txt