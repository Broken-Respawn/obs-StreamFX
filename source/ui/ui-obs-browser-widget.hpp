
#pragma once
#include "util/util-library.hpp"

#include "warning-disable.hpp"
#include <QHBoxLayout>
#include <QSharedPointer>
#include <QUrl>
#include <QWidget>
#include "warning-enable.hpp"

namespace streamfx::ui {
	class obs_browser_cef {
		std::shared_ptr<::streamfx::util::library> _module;

		void* _cef;
		void* _cookie;

		private:
		obs_browser_cef();

		public:
		~obs_browser_cef();

		void* cef();

		void* cookie_manager();

		public: // Singleton
		static std::shared_ptr<obs_browser_cef> instance();
	};

	class obs_browser_widget : public QWidget {
		Q_OBJECT

		std::shared_ptr<obs_browser_cef> _cef;
		QWidget*                         _widget;
		QHBoxLayout*                     _layout;

		public:
		obs_browser_widget(QUrl url, QWidget* parent = nullptr);
		virtual ~obs_browser_widget();

		void set_url(QUrl url);
	};
} // namespace streamfx::ui
