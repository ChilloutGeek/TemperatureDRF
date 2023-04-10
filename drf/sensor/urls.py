from django.urls import path
from .views import TemperatureView

urlpatterns = [
    path('temperature/', TemperatureView.as_view({
        'get':'templist',
        'post':'tempread'
    }))
]
