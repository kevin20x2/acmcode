import requests
import json
r = requests.get('http://www.bilibili.com/index/catalogy/119-3day.json')
ans = json.loads( r.text )
s = 'http://www.bilibili.com/video/av'
for i in range(0,3):
    a =s+str( ans['hot']['list'][i]['aid'])+'/'
    print a 
