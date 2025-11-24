# parameters
param
(
    [string]$Mode = "debug", # default value for -Mode argument
    [string]$Target = "Station93"
)

# variables
$buildDir = "build"
$debugDir = "$buildDir\debug"
$releaseDir = "$buildDir\release"
$selectedDir = $debugDir

if ($Mode -eq "debug") {
    $selectedDir = $debugDir
}
elseif ($Mode -eq "release") {
    $selectedDir = $releaseDir
}

$buildArgs = @(
    "/std:c++20",
    "/EHsc",
    "/Iinclude",
    "src\main.cpp",
    "src\Logic\Game.cpp",
    "src\Logic\Terrains\Terrain.cpp",
    "src\Scenes\MainMenu.cpp",
    "src\Scenes\Scene.cpp",
    "src\Scenes\SceneHandler.cpp",
    "src\Scenes\World.cpp"
    "src\Graphics\Cursor.cpp",
    "src\Graphics\AsciiHandler.cpp",
    "/Fe:$selectedDir/$Target.exe",
    "/Fo:$debugDir/",
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

cl $buildArgs
Write-Host "Compiled in $Mode mode." -ForegroundColor Green

