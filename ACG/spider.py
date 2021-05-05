import urllib.request
from fake_useragent import UserAgent
from bs4 import BeautifulSoup
import re
import sqlite3

def main() :
    url = "https://www.agefans.net/rank?tag=catyear&value=&page="

    dbpath = 'ACG.db'
    init_db(dbpath)
    getData(url,dbpath)
    # saveData(dataList, dbpath)
    print('finished')
    
    

findLink = re.compile(r'<a href="(.*?)">')
findName = re.compile(r'<span class="rank_text_name">(.*?)</span>')
findPopularity = re.compile(r'<span class="rank_value asciifont">(\d*)</span>')
findImgSrc = re.compile(
    r'<img.*class="poster" height="356px" referrerpolicy="no-referrer" src="(.*?)".*/>')
findInformation = re.compile(r'<span class="detail_imform_value">(.*?)</span>')
findIntroduction = re.compile(r'<p>(.*?)</p>')

def askURL(url) :
    ua = UserAgent()
    head = {"User-Agent": ua.random}
    request = urllib.request.Request(url, headers=head)
    html = ""
    response = urllib.request.urlopen(request)
    html = response.read().decode("utf-8")
    return html

def getData(_url,dbpath) :
    print('getting data')

    for i in range(1,40+1) :
        dataList = []
        url = _url + str(i)
        html = askURL(url)
        print('getting %d page`s data'%(i))
        soup = BeautifulSoup(html, "html.parser")

        for item in soup.find_all("li", class_="rank_text") :
            data = []
            item = str(item)

            link = re.findall(findLink, item)[0]
            link = 'https://www.agefans.net' + link
            data.append(re.findall(findName, item)[0])
            data.append(link)
            data.append(re.findall(findPopularity, item)[0])
            
            list = intoURL(link)
            for l in list :
                data.append(l)

            dataList.append(data)
                
        saveData(dataList,dbpath)
    print('got data ok')

def intoURL(link) :
    data = []
    html = askURL(link)

    soup = BeautifulSoup(html, "html.parser")

    itemAll = soup.find_all("div", class_="blockcontent")

    
    #这里要1,2,5部分 1为图片, 2为基本信息, 5为简介
    imgSrc = re.findall(findImgSrc, str(itemAll[0]))[0]
    data.append(imgSrc)
    
    information = re.findall(findInformation, str(itemAll[1]))
    for i in information :
        data.append(i)

    introduction = re.findall(findIntroduction, str(itemAll[4]))[0]
    introduction = introduction.replace("<br/>","")
    data.append(introduction)
    
    return data

def init_db(dbpath) :
    print('creating sql')
    sql = '''
        create table ACG
        (
            id integer primary key autoincrement,
            anime text,
            info_Link text,
            rated numeric, 
            pic_Link text,
            area text,
            kinds text,
            trueName text,
            otherName text,
            author text,
            company text,
            premiere text,
            state text,
            type text,
            label text,
            official text,
            introduction text
        )
    '''

    con = sqlite3.connect(dbpath)
    cursor = con.cursor()
    cursor.execute(sql)
    con.commit()
    con.close()
    print('created sql ok')

def saveData(dataList, dbpath) :
    print('saving')
    
    con = sqlite3.connect(dbpath)
    cursor = con.cursor()

    for data in dataList :
        for index in range(len(data)) :
            data[index] = '"' + str(data[index]).replace('"', "'") + '"'

        sql = '''
            insert into ACG
            (
                anime,info_Link,rated,pic_Link,area,kinds,trueName,otherName,author,company,premiere,state,type,label,official,introduction
            )
            values(%s)'''%",".join(data)
        
        cursor.execute(sql)
        con.commit()
    cursor.close()
    con.close()
    print('saved ok')

if __name__ == "__main__" :
    main()
