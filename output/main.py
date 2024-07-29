from fastapi import FastAPI
app = FastAPI()







@app.get("/users/{id}")
async def get(id : int): dict
	dbGetUsers(id: int) -> dict
@app.post("users/{age}/{name}/{password}")
async def post(username: str, password: str) -> dict:
	'''posts Users with the following fields: username, password
	age, name, password, '''
	return {
		"age": age, 
		"name": name, 
		"password": password, 
	}
@app.put("/users")
async def put(id : int, ), age: int, name: str, password: str: dict
	dbPutUsers(, age , name , password )
@app.delete("/users")
async def delete(id : int): dict
	dbDeleteUsers(id: int)
