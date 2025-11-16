# parameters
param
(
    [string]$Mode = "debug", # default value for -Mode argument
    [string]$Target = "StarTravellerC"
)

# check/create build folder

# variables
$buildDir = "build"
$debugDir = "$buildDir\debug"
$releaseDir = "$buildDir\release"

$debugArgs = @(
    "/std:c++20",
    "/EHsc",
    "/Iinclude",                     # tell compiler to look for includes(I) in a folder called include(include)
    "src\main.cpp",
    "src\Scenes\MainMenu.cpp",
    "src\Scenes\Scene.cpp",
    "src\Scenes\SceneHandler.cpp",
    "src\Graphics\Cursor.cpp",
    "src\Graphics\AsciiHandler.cpp",
    "/Fe:$debugDir\$Target.exe",
    "/Fo:$debugDir/",
    "/link",                        # indicates linker instruction start
    "/LIBPATH:lib",
    "BearLibTerminal.lib"
)
$releaseArgs = @(
    "/std:c++20",
    "/EHsc",
    "/Iinclude",
    "src\main.cpp",
    "src\Scenes\MainMenu.cpp",
    "src\Scenes\Scene.cpp",
    "src\Scenes\SceneHandler.cpp",
    "src\Graphics\Cursor.cpp",
    "src\Interfaces",
    "/Fe:$releaseDir\$Target.exe",
    "/Fo:$releaseDir/",
    "/link",
    "/LIBPATH:lib",
    "BearLibTerminal.lib"
)

Write-Host "Attempting build..." -ForegroundColor Yellow

foreach ($dir in @($buildDir, $debugDir, $releaseDir)) {
    if (!(Test-Path $dir)) {
        New-Item -ItemType Directory -Path $dir
    }
    else {
        Write-Host "⚠️ $dir already exists." -ForegroundColor Yellow
    }
}

if ($Mode -eq "debug") {
    cl $debugArgs
    Write-Host "✅ Compiled in debug mode." -ForegroundColor Green
}
elseif ($Mode -eq "release") {
    cl $releaseArgs
    Write-Host "✅ Compiled in release mode." -ForegroundColor Green
}
else {
    Write-Host "❌ Failed: Input a build mode with -Mode" -ForegroundColor Red
}
