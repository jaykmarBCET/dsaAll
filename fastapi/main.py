from fastapi import FastAPI,Query
from typing import Union,Annotated
from pydantic import BaseModel

class Item(BaseModel):
    name:str
    price:float 
app = FastAPI()

@app.get("/")
def read_root():
    return {"Hello":"world"}
@app.post("/add")
def write_root(item: Item):
    return item


