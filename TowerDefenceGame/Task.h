#pragma once

/// <summary>
/// every scene must implement this interface
/// </summary>
class Task {
public:
	Task() {}
	virtual ~Task() {}

	virtual void Initialize() {}
	virtual void Update() = 0;
	virtual void Draw() = 0;
	virtual void Finalize() {}

};