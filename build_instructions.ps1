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
    cl main.c /Fe:$debugDir\$Target.exe /Fo:$debugDir\$Target.obj
    Write-Host "✅ Compiled in debug mode." -ForegroundColor Green
}
elseif ($Mode -eq "release") {
    cl main.c /Fe:$releaseDir\$Target.exe /Fo:$releaseDir\$Target.obj
    Write-Host "✅ Compiled in release mode." -ForegroundColor Green
}
else
{
    Write-Host "❌ Failed: Input a build mode with -Mode" -ForegroundColor Red
}
