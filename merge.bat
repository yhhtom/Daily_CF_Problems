@echo off
chcp 65001 > nul

call git add -A

call git commit -m "Auto-save: %date% %time%"

call git pull --rebase upstream main

call git push origin main -f

pause