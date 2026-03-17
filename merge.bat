chcp 65001 > nul
call git add -A
call git commit -m "Auto-save before sync"
call git checkout main
call git pull upstream
call git checkout practice
call git merge main
call git checkout practice
call git add -A
call git commit -m "Daily submission: merged upstream updates"
call git push origin practice
pause