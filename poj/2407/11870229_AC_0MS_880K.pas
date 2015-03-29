var
  x,i,p:longint;
begin
  while true do
    begin
      readln(x);
      if x=0 then break;
      p:=x;
      for i:=2 to trunc(sqrt(x)) do
        if x mod i=0 then
          begin
            p:=p-p div i;
            while x mod i=0 do x:=x div i;
          end;
      if x>1 then p:=p-p div x;
      writeln(p);
    end;
end.