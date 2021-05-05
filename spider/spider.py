from bs4 import BeautifulSoup
import re
import urllib.request, urllib.error
import xlwt
import sqlite3
from fake_useragent import UserAgent



def main() :
    baseurl = "https://movie.douban.com/top250?start="
    dataList = getData(baseurl)
    # savePath = '豆瓣.xls'
    dbPath = 'movie.db'
    saveDataToSQL(dataList, dbPath)
    print('OK')


findLink = re.compile(r'<a href="(.*?)">')
findImgSrc = re.compile(r'<img.*src="(.*?)"', re.S)
findTitle = re.compile(r'<span class="title">(.*?)</span>')
findRating = re.compile(r'<span class="rating_num" property="v:average">(.*)</span>')
findJudge = re.compile(r'<span>(\d*)人评价</span>')

def init_db(dbpath) :
    sql = '''
        create table movie
        (
            id integer primary key autoincrement,
            info_Link text,
            pic_Link text,
            cname varchar,
            oname varchar,
            score numeric,
            rated numeric
        )
    '''

    con = sqlite3.connect(dbpath)
    cursor = con.cursor()
    cursor.execute(sql)
    con.commit()
    con.close()

def saveDataToSQL(dataList, dbPath) :
    init_db(dbPath)
    con = sqlite3.connect(dbPath)
    cursor = con.cursor()

    for data in dataList :
        for index in range(len(data)) :
            data[index] = '"' + str(data[index]) + '"'
            
        sql = '''
            insert into movie(
                info_Link,pic_LInk,cname,oname,score,rated
            )
            values(%s)'''%",".join(data)
        cursor.execute(sql)
        con.commit()
    cursor.close()
    con.close()

def saveData(dataList, savePath) :
    print('saving')
    work = xlwt.Workbook(encoding='utf-8')
    sheet = work.add_sheet('sheet')
    col = ('电影详情链接','封面链接','中文名称','英文名称','评分','观看数')
    for i in range(0,6) :
        sheet.write(0,i,col[i])
    for i in range(0,250) :
        data = dataList[i]
        for j in range(0,6) :
            sheet.write(i+1,j,data[j])
    work.save(savePath)

def getData(baseurl) :
    dataList = []

    for i in range(0,10) :
        url = baseurl + str(i*25)
        html = askURL(url)

        soup = BeautifulSoup(html, "html.parser")

        for item in soup.find_all("div", class_ = "item") :
            data = []
            item = str(item)
        
            Link = re.findall(findLink, item)[0]
            data.append(Link)
            imgSrc = re.findall(findImgSrc, item)[0]
            data.append(imgSrc)
            titles = re.findall(findTitle, item)
            data.append(titles[0])
            if len(titles)>1 :
                otitle = titles[1].replace("/", "")
                otitle = otitle.replace(u"\xa0", u"")
                data.append(otitle)
            else :
                data.append(" ")
            rating = re.findall(findRating, item)
            data.append(rating)
            judge = re.findall(findJudge, item)
            data.append(judge)
            
            dataList.append(data)
            
    return dataList

def askURL(url) :
    ua = UserAgent()
    head = {"User-Agent": ua.random}
    request = urllib.request.Request(url, headers=head)
    html = ""

    response = urllib.request.urlopen(request)
    html = response.read().decode("utf-8")
    
    return html


if __name__ == "__main__" :
    main()
