@echo off

git add -A
git commit -m "Auto-save before sync"


git checkout main
git pull upstream main


git checkout practice
git merge main --no-edit


git add -A
git commit -m "Daily submission: merged upstream updates"
git push origin practice
git checkout practice

pause