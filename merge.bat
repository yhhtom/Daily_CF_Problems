@echo off
git checkout main
git pull upstream
git checkout practice
git merge main
git add -A
git commit -m "日常提交"
git push origin