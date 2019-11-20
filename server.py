from flask import Flask
from processing import do_calculation
from flask import render_template
from flask import Response, request, jsonify
app = Flask(__name__)
app.config["DEBUG"] = True
import oct1
import numpy as np

#put the sliding average here
sliding_average = 10;
date = "2018-12-14"
time = "06:58:32 - 07:16:16"
run_number = 0
source = "first_light"
times = []
event_count=[]

@app.route('/hello')
def hello():
	hi = [1,1]
	bi = [2,2]
	calc = do_calculation(hi,bi)
	# calc2 = do_calculation(0,2)
	# calc3 = do_calculation(0,3)
	return render_template('hello.html', calc=calc)


@app.route('/Add_item', methods=['GET', 'POST'])
def Add_item(times=times, event_count=event_count, sliding_average = sliding_average):
   x = np.zeros((2,1000))
   # y = x.copy()
   oct1.modifyArray(x) 

   #print(y)
   print(x[0])
   x.tolist() 
   times = x[0].tolist()
   event_count = x[1].tolist()
   print("part 2")
   print(x[1])
   #array2 = np.zeros((100,))
   #   oct1.hello("FirstLight.fits",100,100, array2)
   #  print(array2[0]);
   return render_template('practice.html', times=times, event_count=event_count, sliding_average=sliding_average, date=date, time=time, run_number=run_number, source=source)

@app.route('/match', methods=['GET', 'POST'])
def add():
	return jsonify()



if __name__ == '__main__':
   app.run(debug = True)


