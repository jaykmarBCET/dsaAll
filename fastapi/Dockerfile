FROM python:3.12.7-slim-bullseye


RUN -m venv /opt/venv

ENV PATH=/opt/venv/bin:$PATH

RUN pip install --upgrade pip

ENV PYTHONDONTWRITEBYTECODE 1
ENV PYTHONUNBEFFERED 1