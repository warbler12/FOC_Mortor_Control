
cd .

if "%1"=="" ("D:\Software\MATLAB\bin\win64\gmake"  DEPRULES=1 -j9  -f pmsm_f28379d_openloop.mk all) else ("D:\Software\MATLAB\bin\win64\gmake"  DEPRULES=1 -j9  -f pmsm_f28379d_openloop.mk %1)
@if errorlevel 1 goto error_exit

exit /B 0

:error_exit
echo The make command returned an error of %errorlevel%
exit /B 1