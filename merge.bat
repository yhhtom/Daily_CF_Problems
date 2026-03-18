@echo off
cd /d D:\NoobProjects\Daily_CF_Problems
call git add -A

call git commit -m "Auto-save: %date% %time%"

call git pull --rebase upstream main

call git push origin main

pause