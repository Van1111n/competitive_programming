# clean.ps1
$exts = @('.exe', '.o', '.out')
$root = (Get-Location).Path

# 收集所有匹配的文件
$files = Get-ChildItem -Path $root -Recurse -File |
         Where-Object { $exts -contains $_.Extension.ToLower() }

if ($files.Count -eq 0) {
    Write-Host "未找到匹配的文件。" -ForegroundColor Yellow
    exit
}

# 显示将删除的文件列表
$files | ForEach-Object { Write-Host $_.FullName }
Write-Host ""
$ans = Read-Host "共 $($files.Count) 个文件，确认删除？(y/N)"
if ($ans -eq 'y' -or $ans -eq 'Y') {
    $files | Remove-Item -Force
    Write-Host "已删除 $($files.Count) 个文件。" -ForegroundColor Green
} else {
    Write-Host "已取消。" -ForegroundColor Cyan
}