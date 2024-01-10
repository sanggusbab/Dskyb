import httpx
from datetime import datetime
# �񵿱� Ŭ���̾�Ʈ ����
async def A_client(request, location_x, location_y, start_time, user_id, task_id, task_group):
    async with httpx.AsyncClient() as client:
        # ������ ���� ������ ����
        data = {
            "request": request,
            "location_x": location_x,
            "location_y": location_y,
            "start_time": start_time,
            "user_id": user_id,
            "task_id": task_id,
            "task_group": task_group
        }
        response = await client.post("http://localhost:8000/", json=data)
        print("POST ��û ����:", response.json())

def A_run():
    import asyncio
    while True:
        print("------------------------")
        request = input("����� �Է��ϼ���: ")
        location_x = float(input("location_x: "))
        location_y = float(input("location_y: "))
        current_time = datetime.now()
        start_time = current_time.strftime("%Y-%m-%dT%H:%M:%S")
        user_id = int(input("user_id: "))
        task_id = int(input("task������ �Է��ϼ���: "))
        task_group = int(input("�׷� ������ �Է��ϼ���: "))
        asyncio.run(A_client(request, location_x, location_y, start_time, user_id, task_id, task_group))


if __name__ == "__main__":
    A_run()
import httpx

# 비동�? ?��?��?��?��?�� ?��?��
async def A_client(request, task_id, task_group):
    async with httpx.AsyncClient() as client:
        # ?��버에 보낼 ?��?��?�� ?��?��
        data = {
            "request": request,
            "location_x": 1.0,
            "location_y": 2.0,
            "start_time": "2023-12-13T08:30:00",
            "user_id": 1,
            "task_id": task_id,
            "task_group": task_group
        }
        response = await client.post("http://localhost:8000/", json=data)
        print("POST ?���? ?��?��:", response.json())

def A_run():
    import asyncio
    while True:
        request = input("명령?�� ?��?��?��?��?��: ")
        task_id = int(input("task?��보�?? ?��?��?��?��?��: "))
        task_group = int(input("그룹 ?��보�?? ?��?��?��?��?��: "))
        asyncio.run(A_client(request, task_id, task_group))


if __name__ == "__main__":
    A_run()