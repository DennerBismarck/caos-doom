from flask import Flask, redirect, render_template

app = Flask(__name__)

@app.route("/~lpab")
def root():
    return redirect("~lpab/main")

@app.route("/~lpab/igg")
def fool():
    return "<p> Oops, you found me! </p> <a href='/~lpab/main'> Go back! </a>"

@app.route("/~lpab/main")
def mainPage():
    return render_template("curriculum.html")

@app.route("/~lpab/students")
def studentsPage():
    return "<p> Students Page </p>"

@app.route("/~lpab/students/<name>")
def studentCurriculum(name=None):
    return f"<p> Hello, {name} </p>"

@app.route("/~lpab/materials")
def materialsPage():
    return "<p> Materials Page Listing </p>"

@app.route("/~lpab/materials/<index>")
def materialUnitPage(index=None):
    return f"<p> This is material {index}. </p>"