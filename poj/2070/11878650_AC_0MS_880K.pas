var
  x,y,z:extended;
  f:boolean;
begin
  while true do
    begin
      readln(x,y,z);
      if x=0 then break;
      f:=false;
      if (x<=4.5)and(y>=150)and(z>=200) then begin write('Wide Receiver ');f:=true;end;
      if (x<=6.0)and(y>=300)and(z>=500) then begin write('Lineman ');f:=true;end;
      if (x<=5.0)and(y>=200)and(z>=300) then begin write('Quarterback ');f:=true;end;
      if not f then write('No positions');
      writeln;
    end;
end.