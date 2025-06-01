from fastapi import FastAPI
from pydantic import BaseModel,Field


class Item(BaseModel):
    name:str
    description:str | None = Field(default=None,title="tell about item",max_length=100)
    price:float | None = Field(default=0,title="price of this products",max_digits=1000000)
    tax:float | None = Field(default=0,title="please enter tax of this items")    


app = FastAPI()

@app.get('/')
async def home():
    return {
        "message":"Ok server is running"
    }