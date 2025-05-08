# Аттракцион "Магнитная рыбалка"

> [!NOTE]
> Аттракцион сделан по мотивам известных призовых автоматов [кран-машина](https://ru.wikipedia.org/wiki/%D0%9A%D1%80%D0%B0%D0%BD_(%D0%B8%D0%B3%D1%80%D0%BE%D0%B2%D0%BE%D0%B9_%D0%B0%D0%B2%D1%82%D0%BE%D0%BC%D0%B0%D1%82)) в рамках курса ППП (прототипирование, проектирование, производство) на *Физтех.Фабрике*. :smile:


<img src="https://github.com/kseniadobrovolskaia/MagneticFishing/blob/main/Pictures/result.jpg" width="500">

## Содержание

[1. Прототипирование](#1)

Три+ версий аттракциона

[2. Проектирование](#2)

Разработка в *SolidWorks* -> *CorelDraw*

[3. Производство](#3)

Лазерные станки

[4. Работа аттракциона](#4)


 -----------------------------------------------------------------------------

<a name="1"></a>
 ## Прототипирование

Это было самым долгим и сложным процессом в работе над проектом. Было много вариантов системы, расскажем о наиболее отличающихся друг от друга.

### Вариант 1

В первом варианте аттракциона было рассчитано, что движение управляющего механизма по осям x и y будет происходить в одну сторону за счет тяги сервоприводов, а в другую за счет силы тяжести:

<img src="https://github.com/kseniadobrovolskaia/MagneticFishing/blob/main/Pictures/prototip1.png" width="500">

Проведя моделирование такой системы, было выяснено, что трение слишком велико и требуется добавить грузы. 

### Вариант 2

Тогда можно было отказаться от наклонного механизма и оставить одно колесо и рельсу для каждой оси:

<img src="https://github.com/kseniadobrovolskaia/MagneticFishing/blob/main/Pictures/prototip2.png" width="500">

Моделирование такого варианта тоже закончилось плохо и мы добавили вторые колеса и рельсы:

<img src="https://github.com/kseniadobrovolskaia/MagneticFishing/blob/main/Pictures/modelirovanie_koles.jpg" width="500">

Но возникла проблема в другом: система с грузом и одним серво была несимметрична, поэтому попытка поехать заканчивалась перекошенным и вставшим механизмом. 

### Вариант 3

Было решено добиться симметрии, установив серво внизу и распределив его силу на оба колеса с помощью шестеренок:

<img src="https://github.com/kseniadobrovolskaia/MagneticFishing/blob/main/Pictures/prototip3.png" width="500">

Шестеренки вырезали из дерева:

<img src="https://github.com/kseniadobrovolskaia/MagneticFishing/blob/main/Pictures/shesterenki.jpg" width="500">

Этот механизм уже заработал:

![](Pictures/first_result.gif)  

Но мы поняли, что колеса почти не вращаются, поэтому их можно заменить на обычные плоские наконечники для палок:

<img src="https://github.com/kseniadobrovolskaia/MagneticFishing/blob/main/Pictures/nakonechniki_dlia_palok.jpg" width="500">

Это стало окончательным вариантом движущегося механизма.
 
 -----------------------------------------------------------------------------
 <a name="2"></a>
 ## Проектирование

Использовалась CAD/CAM система *SolidWorks*. В ней были разработаны главные компоненты аттракциона:

1. [**Корпус**](https://github.com/kseniadobrovolskaia/MagneticFishing/blob/main/SolidWorksFiles/корпус.SLDPRT)

<img src="https://github.com/kseniadobrovolskaia/MagneticFishing/blob/main/Pictures/KorpusSW.png" width="500">

2. [**Шестеренки**](https://github.com/kseniadobrovolskaia/MagneticFishing/blob/main/SolidWorksFiles/шестеренка.SLDPRT) 

<img src="https://github.com/kseniadobrovolskaia/MagneticFishing/blob/main/Pictures/ShecterenkiSW.png" width="500">

3. [**Наконечники для палок**](https://github.com/kseniadobrovolskaia/MagneticFishing/blob/main/SolidWorksFiles/таскалки.SLDPRT) 

<img src="https://github.com/kseniadobrovolskaia/MagneticFishing/blob/main/Pictures/TaskalkiSW.png" width="500">
 
4. [**Удочка**](https://github.com/kseniadobrovolskaia/MagneticFishing/blob/main/SolidWorksFiles/удочка.SLDPRT) 

<img src="https://github.com/kseniadobrovolskaia/MagneticFishing/blob/main/Pictures/YdochkaSW.png" width="500">
 
5. [**Джостик для кнопок**](https://github.com/kseniadobrovolskaia/MagneticFishing/blob/main/SolidWorksFiles/джостик_с_кнопками.SLDPRT) 

<img src="https://github.com/kseniadobrovolskaia/MagneticFishing/blob/main/Pictures/DjosticSW.png" width="500">

Далее плоскости всех объектов были импортированы в *DXF* формат и открыты в системе *CorelDraw* для отправки на печать. В этой же системе были разработаны остальные простые детали, не требующие соединений шип-паз.


 -----------------------------------------------------------------------------

 <a name="3"></a>
 ## Производство

Для печати корпуса была использована деревянная фанера 6 мм и большой лазерный станок:

![](Pictures/big_laser.gif)  

Для остальных комплектующих - фанера 3 мм и маленький лазерный станок:

![](Pictures/small_laser.gif)  

Для управления механизмом была использована плата микроконтроллера Arduino MEGA. К ней были припаяны кнопки, реализующие [логику сервоприводов](https://github.com/kseniadobrovolskaia/MagneticFishing/blob/main/ServoProg/sketch_servo.ino) для управления движением магнита по осям x и y:

![](Pictures/servo.gif)  

Сервоприводы были закреплены в дне корпуса. Колеса соединены нитками с катушкой вращающего механизма с одной стороны и с утяжеляющей конструкцией, за счет которой происходит движение в обратном направлении.


 -----------------------------------------------------------------------------

 <a name="4"></a>
 ## Работа аттракциона

> [!IMPORTANT]
> Магнит не является электрическим, а выдача призов происходит не как в известном автомате, потому что аттракцион задуман, как имитация настоящей рыбалки, где тащить рыбу нужно самостоятельно :smile:

![](Pictures/ydochka.gif)  

