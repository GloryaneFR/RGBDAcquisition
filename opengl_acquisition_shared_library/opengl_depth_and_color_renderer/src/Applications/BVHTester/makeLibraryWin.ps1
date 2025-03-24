$CURRENT_DIR = $PSScriptRoot
Set-Location "$CURRENT_DIR"

Set-Location ..
$REPO= Get-Location
Set-Location "$CURRENT_DIR"

Write-Output "JIT Python/C Compilation *made by AmmarTM* handled by : "
$BVHTESTER_OBJ_DIR="$REPO/RGBDAcquisition/opengl_acquisition_shared_library/opengl_depth_and_color_renderer/build/src/Applications/BVHTester/BVHTester.dir/Release"
$PTHREAD_LIB_DIR="$REPO/pthreads4w/PTHREADS-BUILT/x86_64/Debug/lib"

# Create shared library DLL file
# & link /DLL /OUT:libBVHConverter.dll "$BVHTESTER_OBJ_DIR/*.obj" "$PTHREAD_LIB_DIR/pthread.lib" /VERBOSE
# cl /nologo /EHsc /Od /I. build\main.obj /Fe"build\dynamicLibExample.exe" /link /DLL /LIBPATH:build build\libMyMath.lib
cl /D_USRDLL /D_WINDLL "$BVHTESTER_OBJ_DIR/*.obj" "$PTHREAD_LIB_DIR/pthread.lib" /link /DLL /OUT:libBVHConverter.dll #/VERBOSE


if ($?)
{
    Write-Output "DLL libBVHConverter.dll file created succesfully"
}
else
{
    Write-Output "Error: Unable to compile BVH library, This probably means that you have library dependencies missing ..."
}
exit 0
