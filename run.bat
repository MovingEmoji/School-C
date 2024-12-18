@echo off
setlocal enabledelayedexpansion
set /p file_name=C-Lang file name: 
gcc %file_name%
if %ERRORLEVEL% == 0 (
    echo compile succeeded
    echo プログラムを実行します...
    echo [実行結果]
    a.exe
    set /p copy_bool=確認フォルダに書き込みますか[y/n]: 
    if "!copy_bool!" == "y" (
        echo 確認フォルダに %file_name% を書き込みます...
        copy %file_name% N:\Kakunin\c\%file_name%
    ) else (
        echo no
    )
) else (
    echo compile failed
)
pause