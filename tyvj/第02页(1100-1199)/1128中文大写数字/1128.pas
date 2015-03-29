var
  a,x:int64;
  i,j,b,c,d:longint;
  t:boolean;
begin
  readln(a);if a=0 then begin writeln(0);halt;end;
  x:=a;
  i:=a div 100000000;
  if i>0 then
    begin
      b:=i div 10;
      if b>0 then write(b,'shi');
      c:=i mod 10;
      if c>0 then write(c);
      write('yi');
    end;
  a:=a mod 100000000;
  i:=a div 10000;
  if i>0 then
    begin
      j:=i div 1000;i:=i mod 1000;
      b:=i div 100;i:=i mod 100;
      c:=i div 10;i:=i mod 10;
      d:=i;
      if j>0 then write(j,'qian');t:=false;
      if (j=0)and(b>0)and((c>0)or(i>0))and(x>100000000)and(not t) then begin write(0);t:=true;end;
      if (b=0)and((c>0)or(i>0))and(x>100000000)and(not t) then begin write(0);t:=false;end;
      if b>0 then write(b,'bai');
      if c>0 then write(c,'shi');
      if ((j>0)or(b>0))and(c=0)and(d>0)and t then write(0);
      if d>0 then write(d);
      write('wan');
    end;
  a:=a mod 10000;
  i:=a;
  if i>0 then
    begin
      j:=i div 1000;i:=i mod 1000;
      b:=i div 100;i:=i mod 100;
      c:=i div 10;i:=i mod 10;d:=i;
      if j>0 then write(j,'qian');t:=false;
      if (j=0)and(b>0)and((c>0)or(i>0))and(x>10000)and(not t) then begin write(0);t:=true;end;
      if (b=0)and((c>0)or(i>0))and(x>10000)and(not t) then begin write(0);t:=false;end;
      if b>0 then write(b,'bai');
      if c>0 then write(c,'shi');
      if ((j>0)or(b>0))and(c=0)and(d>0)and t then write(0);
      if d>0 then write(d);
    end;
  writeln;
end.