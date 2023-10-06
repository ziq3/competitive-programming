# Set the source directory path as a variable
$name = ""
$sourceDirectory = $name

# Concatenate the source directory path with "inp" to create the destination directory path
$destinationDirectory = $name + "inp"

# Check if the destination directory exists, and create it if not
if (!(Test-Path -Path $destinationDirectory -PathType Container)) {
    New-Item -Path $destinationDirectory -ItemType Directory
}

# Copy "word.inp" files from subfolders in the source directory to the destination directory with renaming if necessary
$counter = 0
Get-ChildItem -Path $sourceDirectory -File -Recurse -Filter "*.inp" | ForEach-Object {
    $baseFileName = [System.IO.Path]::GetFileNameWithoutExtension($_.Name)
    $newFileName = $baseFileName + "_$counter.inp"
    $destinationPath = Join-Path -Path $destinationDirectory -ChildPath $newFileName
    while (Test-Path -Path $destinationPath) {
        $counter++
        $newFileName = $baseFileName + "_$counter.inp"
        $destinationPath = Join-Path -Path $destinationDirectory -ChildPath $newFileName
    }
    Copy-Item -Path $_.FullName -Destination $destinationPath -Force
}

Write-Host "Files copied successfully to $destinationDirectory."
