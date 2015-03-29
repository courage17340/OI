var
  s,t:string;
  n,i,h:longint;
begin
  readln(n);
  for i:=1 to n do
    begin
      readln(s);
      write(copy(s,6,5),s[5],copy(s,1,4),s[11]);
      delete(s,1,11);
      val(copy(s,1,2),h);
      if h>=12 then t:='pm' else t:='am';
      if h>12 then h:=h mod 12;
      if (h<10)and(h>0) then write(0);
      if h=0 then write(12) else write(h);
      writeln(copy(s,3,6),t);
    end;
end.