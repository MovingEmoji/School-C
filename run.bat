@echo off
setlocal enabledelayedexpansion
set /p file_name=C-Lang file name: 
gcc %file_name%
if %ERRORLEVEL% == 0 (
    echo compile succeeded
    echo �v���O���������s���܂�...
    echo [���s����]
    a.exe
    set /p copy_bool=�m�F�t�H���_�ɏ������݂܂���[y/n]: 
    if "!copy_bool!" == "y" (
        echo �m�F�t�H���_�� %file_name% ���������݂܂�...
        copy %file_name% N:\Kakunin\c\%file_name%
    ) else (
        echo no
    )
) else (
    echo compile failed
)
pause