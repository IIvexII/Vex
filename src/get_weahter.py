#!/usr/bin/python
import sys
import urllib
from urllib.request import urlopen
from xml.dom.minidom import parse
import xml.dom.minidom

error = 0
f = open("weather_info.txt","r")

city=f.readline()

f.close()

f = open("weather_info.txt","w")

city = city.replace("_", " ") 
city = urllib.parse.quote(city)

api_key = "0e8c8fdda3060d4965df9d83e84ed56e"
try:
    xml_page = urlopen(f'https://api.openweathermap.org/data/2.5/weather?q={city}&appid={api_key}&mode=xml&units=metric')
except:
    f.write("404")
    error = 1
if not error:
    # Open XML document using minidom parser
    DOMTree = xml.dom.minidom.parse(xml_page)
    collection = DOMTree.documentElement

    country = collection.getElementsByTagName('country')[0]
    f.write(f"{country.childNodes[0].data}\n")

    city = collection.getElementsByTagName('city')[0]
    f.write(f"{city.getAttribute('name')}\n")

    temperature = collection.getElementsByTagName('temperature')[0]
    f.write(f"{temperature.getAttribute('value')} {temperature.getAttribute('unit')}\n")

    feel_like = collection.getElementsByTagName('feels_like')[0]
    f.write(f"{feel_like.getAttribute('value')} {feel_like.getAttribute('unit')}\n")

    humidity = collection.getElementsByTagName('humidity')[0]
    f.write(f"{humidity.getAttribute('value')}{humidity.getAttribute('unit')}\n")

    pressure = collection.getElementsByTagName('pressure')[0]
    f.write(f"{pressure.getAttribute('value')} {pressure.getAttribute('unit')}\n")

    wind_speed = collection.getElementsByTagName('speed')[0]
    f.write(f"{wind_speed.getAttribute('name')}\n")
    f.write(f"{wind_speed.getAttribute('value')} {wind_speed.getAttribute('unit')}\n")

    wind_direction = collection.getElementsByTagName('direction')[0]
    f.write(f"{wind_direction.getAttribute('value')} {wind_direction.getAttribute('name')}\n")

    clouds = collection.getElementsByTagName('clouds')[0]
    f.write(f"{clouds.getAttribute('name')}\n")

    visibility = collection.getElementsByTagName('visibility')[0]
    f.write(f"{int(visibility.getAttribute('value'))/1000}km\n")

    weatehr = collection.getElementsByTagName('weather')[0]
    f.write(f"{weatehr.getAttribute('value')}\n")

f.close()