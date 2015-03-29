var
  a,b,x:longint;
procedure swap(var a,b:longint);
var t:longint;
begin t:=a;a:=b;b:=t;
end;
begin
  readln(a,b);
  if a<b then swap(a,b);
  if a mod b=0 then writeln(a)
    else
      begin
        x:=a+b;
        while b>0 do
          begin
            if a<b then swap(a,b);
            if b>0 then a:=a mod b;
          end;
        writeln(x-a);
      end;
end.