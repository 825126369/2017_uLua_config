set nopause=true

cd CrocodileConfig
call BuildServer.bat

cd ..
cd DiceConfig
call BuildServer.bat

cd ..
cd FishConfig
call BuildServer.bat

cd..
cd GameConfig
call BuildServer.bat

cd..
cd BaccaratConfig
call BuildServer.bat

cd..
cd CowsConfig
call BuildServer.bat

cd..
cd Dragons
call BuildServer.bat

cd..
cd CalfRopingConfig
call BuildServer.bat

cd..
cd ShcdCardsConfig
call BuildServer.bat

cd..
pause
