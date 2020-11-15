#include "DeliveryTruck.h"

DeliveryTruck::DeliveryTruck(Truckload aTruckload)
  : m_truckload{ std::move(aTruckload) }   // Do not copy!
{}

void DeliveryTruck::deliverBox(SharedBox box)
{
  m_truckload.removeBox(box);
  
  // Notify all interested parties (aka "observers") that the Box was delivered
  for (auto& callback : m_callbacks)
    callback(box);
}

void DeliveryTruck::registerOnDelivered(Callback callback)
{
  m_callbacks.push_back(std::move(callback));   // Do not copy!
}