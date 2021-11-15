#pragma once

namespace Alfred {

	class ContainerStation {
	public:
		static ContainerStation* getInstance();
	private:
		static ContainerStation* me;

		ContainerStation();
	};

}
