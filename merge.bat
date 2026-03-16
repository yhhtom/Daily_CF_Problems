@echo off
git checkout main
git pull upstream
git checkout practice
git merge main
git add -A
git commit -m "Daily submission"
git push origin
git checkout practice