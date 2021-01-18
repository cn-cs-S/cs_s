/**
*   此为本人学习web前端时的js笔记
*   仅为本人观看使用
*/

// window.alert()   警告框
// document.write()  写入html输出
// innerhtml  写入html元素
// document.getElementById(id)  访问html元素
// document.getElementById().innerhtml  写入html元素
// console.log()  写入浏览器控制台

// var声明变量 function声明函数

// js是动态数据类型,字符串和数字相加会把数字转化为字符串;
// 科学计数法如123e5 == 12300000;

// js中object类型中可以定义方法;
// 访问属性方式.运算符或["name"];
// this不同于cpp中,这里this不是一个指针,使用方法为this.xxx;
// 关键字new用来声明js对象变量如:var x = new Number
// P.S.不把字符串,数值,bool值声明为对象

/**
 * &常见html事件
 *  onchange    html已被改变
 *  onclick     用户点击了html元素
 *  onmouseover 用户把鼠标移动到html元素上
 *  onmouseout  用户把鼠标移开html元素
 *  onkeydown   用户按下键盘按键
 *  onload      浏览器已经完成页面加载
 */

/**
 * &字符串的方法和属性
 * 
 * length返回字符串长度 var str;str.length
 * 
 * indexOf方法返回字符串中指定文本首次出现的索引（位置）
 * lastIndexOf 方法返回指定文本在字符串中最后一次出现的索引
 * 两种方法都接受第二个参数--检索位置起点
 * search方法搜索特定值的字符串，并返回匹配的位置
 * 
 * slice substring截取字符串中的某个部分(start,end),substring的参数不饿为负
 * sunstr(start,length)
 * 
 * replace用另一个值替换字符串中指定的值
 * relpace不会改变调用的字符串,返回的是新字符串
 * 默认之替换首个匹配,对大小写敏感
 * 对大小写不敏感:/str/i 替换所有匹配/str/g
 * 
 * toUpperCase转化为大写
 * toLowerCase转化为小写
 * 
 * concat连接两个或多个字符串 等同于string+string
 * trim删除字符串两端的空白符 //! IE8及更低版本不支持
 */

 /**
  * &数字
  * 
  * js数值始终是64位浮点数
  * 整数精确到15位 小数17位 //! 小数计算不精准,可转化为整数计算
  * 
  * 数字和字符串相加等同于字符串相加,但是js会尝试把字符串转化为数字
  * NaN表示某个数不是合法数 isNaN()判断某个数是否是数
  * 
  * Infinity是js在计算数时超出最大可能输范围是返回的值
  * 
  * toString() 以字符串方式返回数值 可以把数输出为十六进制 八进制或二进制
  * toExponential() 返回字符串值,参数为坂柳小数位数,以指数形式返回
  * toFixed() 返回字符串值,参数为小数位数,以小数形式返回
  * toPrecision() 返回字符串值,参数为数字长度,以小数形式返回
  * valueOf() 返回数值
  * 
  * Number() 返回数字.由其参数转换而来
  * 可以将日期转换为数字 返回由...至今的毫秒数
  * parseInt() 解析字符串返回数值,之返回首个数字
  * paseFloat() 同上
  */

  /**
   * &数组
   * 
   * 数组是object array可以存array
   * length返回元素个数
   * join()将所有元素结合为一个字符串,参数接受分隔符
   * 
   * pop删除最后一个元素,返回被弹出的值
   * push添加元素 array.push(...) == array[array.length] = ...
   * shift删除首个元素,把其他元素前移,返回弹出元素
   * unshift在开丫头添加元素,把其他元素后移,返回新数组长度
   * 
   * splice()第一个参数定义添加元素的位置,第二个参数定义删除多少元素,其余为新元素
   * splice()可用来删除元素
   * 
   * concat()合并数组,返回一个新数组,可接受值为参数,可接受任意数量参数
   * slice()剪切数组,接受两个参数,开始的下标,结束的下标
   * 
   * sort()对数组元素进行排序
   * reverse()反转数组元素
   * sort会按照字符串顺序排序,故对数字排序会有问题
   * sort(function(a,b){return a-b}) 如此可解决,也可逆序排序 (类似cmp)
   * sort(function(a, b){return 0.5 - Math.random()}) 以随机顺序排序
   * 
   * 数组迭代对每一个数组进行操作,详情百度
   */

   /**
    * &日期
    * 
    * new Data()用来创建日期对象
    * 空参数表示当前时间创建
    * 里面有至多七个参数 年,月,日,小时,分钟,秒,毫秒
    * 不能省略月份,只有一个参数视作毫秒
    * 一位或两位数年份被解释为上个世纪(19xx)
    * js将日期储存为毫秒,0 == 1970.1.1.00:00:00
    * 
    * toUTCString() 方法将日期转换为 UTC 字符串（一种日期显示标准)
    * toDateString() 方法将日期转换为更易读的格式
    * 
    * ISO日期 "YYYY-MM-DDTHH:MM:SS"
    * 短日期 "MM/DD/YYYY" //!某些浏览器不带前导零的月会产生错误
    * !YYYY/MM/DD 和 DD-MM-YYYY 行为未定义
    * 长日期 "MMM DD YYYY" 月和天顺序随意,月能以全称和缩写,逗号忽略,大小写不敏感
    * 
    * 返回日期方法 getXxx() getUTCXxx() getTime()获取时间,从1970-1-1至今
    * 设置日期方法 setXxx() P.S.像是get set函数
    */