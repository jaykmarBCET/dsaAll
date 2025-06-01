from fastapi import FastAPI,status,Response,requests
from typing import Optional

app = FastAPI()

# Route 1
@app.get("/")
def read_root():
    return {"message": "Hello, FastAPI!"}

# Route 2
@app.get("/home")
def home():
    return {"message": "Ok"}

# Route 3
@app.get("/about/{userid}")
def about(userid: int, skip: Optional[int] = 0, message: Optional[str] = "No message"):
    return {
        "userid": userid,
        "skip": skip,
        "message": message
    }

@app.get('/nice/{id}')
def nice(id:int , name:str):
    return {
        id,name
    }