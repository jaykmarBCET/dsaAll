from fastapi import FastAPI, Request, Response
from pydantic import BaseModel
import matplotlib.pyplot as plt
from io import BytesIO
from typing import List

app = FastAPI()

# Pydantic model for input validation
class ArrayInput(BaseModel):
    data: List[float]

@app.post("/chart")
def generate_chart(input_data: ArrayInput):
    data = input_data.data
    indices = list(range(1, len(data) + 1))

    # Create bar chart
    fig, ax = plt.subplots(figsize=(6, 4))
    ax.bar(indices, data, color='skyblue')
    ax.set_title("Tabular Bar Chart")
    ax.set_xlabel("Index")
    ax.set_ylabel("Value")
    ax.set_xticks(indices)

    # Save figure to in-memory buffer
    buf = BytesIO()
    plt.savefig(buf, format='png', bbox_inches="tight")
    plt.close(fig)
    buf.seek(0)

    return Response(content=buf.read(), media_type="image/png")
