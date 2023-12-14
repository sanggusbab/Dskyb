from fastapi import FastAPI
from pydantic import BaseModel
import threading
import sys, os

sys.path.append(os.path.dirname(os.path.abspath(os.path.dirname(__file__))))

from D_public import database #import engineconn
from D_public import models #import tbl

engine = database.engineconn()
session = engine.sessionmaker()
conn = engine.connection()

app = FastAPI()


class Item(BaseModel):
    request_id: int

# 파일 접근을 동기화하기 위한 Lock 객체 생성
file_lock = threading.Lock()


@app.post("/D1")
async def D1_server(item: Item): # TODO: you need to change when setting server sample script

    response = session.query(models.score_request_queue_tbl).filter(models.score_request_queue_tbl.request_id == item.request_id)[0].task_subgroup_code
    detail_tbl = session.query(models.subgroup_detail_tbl).filter(models.subgroup_detail_tbl.task_subgroup_code == response).all()
    
    # AI로직 추가
    # AI로직 추가
    # AI로직 추가

    data = models.score_tbl(
    expected_score = expected_score, expected_time = expected_time, request_id = item.request_id
    )
    session.add(data)
    session.commit()
    return 'success'

    
def D1_run(): # TODO: you need to change when setting server sample script
    import uvicorn
    uvicorn.run(app, host="0.0.0.0", port=8002) # TODO: you need to change when setting server sample script


if __name__ == "__main__":
    D1_run() # TODO: you need to change when setting server sample scripts