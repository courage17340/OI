var
  n,x,y,z,d:longint;
begin
  readln(n);
  for d:=6 to n do
    begin
      for x:=2 to d-1 do
        begin
          if x*x*x*3>=d*d*d then break;
          for y:=x+1 to d-1 do
            if x*x*x+y*y*y*2<=d*d*d then
              begin
                z:=trunc(exp(1/3*ln(d*d*d-x*x*x-y*y*y)));
                if (z>1)and(x*x*x+y*y*y+z*z*z=d*d*d)
                  then writeln('Cube = ',d,', Triple = (',x,',',y,',',z,')');
              end;
        end;
    end;
end.